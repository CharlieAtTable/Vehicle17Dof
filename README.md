# 多自由度乘用车模型
---
## 模型概述
- 模型组成
   1. sprung，车身，簧上质量
   2. areo，空气动力学
   3. steering_system，转向系统，方向盘到转向机构
   4. powertrain，动力系统，从原动机到驱动轴
   5. hitch，拖车挂点
   6. axle，车轴
      - tire，轮胎
      - driveline，传动系统，只有驱动轴有，从驱动轴到轮上
      - suspension，悬架
      - steering，转向，转向机构到车轮，只有转向轴有
      - location，位置
- 文件组织
  ```mermaid
  graph LR
    vehicle[vehicle.json] --> sprung[sprung.json]
    vehicle --> areo[areo.json]
    vehicle --> steering_system[steering_system.json]
    vehicle --> powertrain[powertrain.json]
    vehicle --> hitch[hitch.json]
    vehicle --> axle((axle))
    axle --> tire[tire.json]
    axle --> driveline[driveline.json]
    axle --> suspension[suspension.json]
    axle --> steering[steering.json]
    axle --> location((location))
    tire --> vertical_stiff
    tire --> radius
    tire --> Fx-kappa
    tire --> Fy-alpha
    tire --> Fy-gamma
    tire --> Mz-alpha
    areo --> refer_point
    areo --> geo_scal
    areo --> coef
    coef --> cfx
    coef --> cfy
    coef --> cfz
    coef --> cmx
    coef --> cmy
    coef --> cmz
    powertrain --> Engine
    powertrain --> Transmission
    Engine --> Maximal_Engine_Speed_RPM
    Engine --> Map_Full_Throttle
    Engine --> Map_Zero_Throttle
    Transmission --> Reverse_Gear_Ratio
    Transmission --> Forward_Gear_Ratio
    Transmission --> Shift_Points_Map_RPM
    driveline --> Differential_Max_Bias
    sprung --> M
    sprung --> Ix
    sprung --> Iy
    sprung --> Iz
    steering_system --> ratio
    steering --> steer_wheel
    steering --> damping
    steering --> hysteresis
    steering --> hys_ref_ang
    steering --> K
    steering --> C
    K --> ratio_
    K --> left
    K --> right
    C --> tie_rod
    C --> column
    suspension --> unsprung_mass
    suspension --> spin_inertia
    suspension --> xxzz_inertia
    suspension --> track_width
    suspension --> K_
    suspension --> C_
    K_ --> dive --> x
    K_ --> roll --> y
    K_ --> toe
    C_ --> springs
    C_ --> dampers
    C_ --> stops
    C_ --> roll_
    C_ --> complicane
    springs --> stiff
    springs --> cmp_jounce
    dampers --> force
    dampers --> cmp_jounce_
    stops --> jounce
    stops --> rebound
    stops --> cmp_jounce__
    complicane --> toe_fx
    complicane --> steer_fy
    complicane --> steer_mz
    complicane --> camber_fx
    complicane --> inc_fy
    complicane --> inc_mz
    complicane --> long_fx
    complicane --> lateral_fy
    complicane --> dive_mbrake
  ```
- 程序实现
  - 前处理
    读取JSON文件来初始化类。[^2]
  - 求解
    使用Eigen求解。所有物理量采用国际单位制(Système International d'Unités)。[^3]
  - 后处理
    数据保存到CSV文件。仿真动画准备用pybullet实现。[^1]
- 数据流
  ```mermaid
  graph LR
      driver -->|throttle| powertrain
      driver -->|steering, braking| vehicle
      powertrain -->|torque| vehicle
      vehicle -->|speed| powertrain
      vehicle -->|wheel state| tire
      tire -->|force, moment| vehicle
      terrain -->|height normal| tire
  ```
---
## 数学模型
- 符号意义
  - sprung
  $M$——簧上质量
  $Ix, Iy, Iz$——转动惯量
  - areo
  $refer-point$——空气动力作用点，相对簧上质量坐标系
  $geo-scal$——A:frontal area; L:reference length; D:air density; $$Q = D*v^2/2$$ $$Fx = -CFx*A*Q$$ $$Fy = -CFy*A*Q$$ $$Fz = CFz*A*Q$$ $$Mx = CMx*A*L*Q$$ $$My = -CMy*A*L*Q$$ $$Mz = -CMz*A*L*Q$$
  $coef$——侧偏角（角度制）与系数关系
  - steering_system
  $ratio$——方向盘到转向机构传动比
  - powertrain
  $Engine$——发动机相关
  $Maximal Engine Speed RPM$——发动机最高转速
  $Map Full Throttle, Map Zero Throttle$——满油门，零油门时发动机map图，rpm-Nm
  $Transmission$——传动相关
  $Reverse Gear Ratio, Forward Gear Ratio$——档位传动比
  $Shift Points Map RPM$——换档发动机转速
  - hitch
  - tire
  $vertical-stiff$——垂向刚度
  $radius$——轮胎半径
  $Fx$——纵滑率-单位纵向力
  $Fy$——侧偏角（角度制）-单位侧向力
  $Mz$——侧偏角（角度制）-单位回正力矩
  $Fy-camber$——外倾角（角度制）-单位侧向力
  - driveline
  $Differential Max Bias$——簧上质量
  - suspension
  $M$——簧上质量
  $M$——簧上质量
  $M$——簧上质量
  $M$——簧上质量
  $M$——簧上质量
  $M$——簧上质量
  $M$——簧上质量
  $M$——簧上质量
  $M$——簧上质量
  $M$——簧上质量
  $M$——簧上质量
  $M$——簧上质量
  - steering
  $steer-wheel$——参考的转向轮
  $M$——簧上质量
  $M$——簧上质量
  $M$——簧上质量
  $M$——簧上质量
  $M$——簧上质量
  $M$——簧上质量
  $M$——簧上质量
  $M$——簧上质量
  $M$——簧上质量
  $M$——簧上质量
  $M$——簧上质量
- 坐标系
  在车身坐标系中建模。
- 推导过程
  使用Maple或Mathematica推导。[^0]




[^0]: Maple方案已经较为成熟，但是实验室只获得了Mathematica的License。
[^2]: 使用[nlohmann](https://github.com/nlohmann/json)。
[^1]: Python和C++的交互可以尝试[Pybind11](https://github.com/pybind/pybind11)。
[^3]: 特别强调，角度单位为rad，而不是°；速度单位为m/s，而不是km/h或mph；转速单位为rad/s，而不是r/min。
