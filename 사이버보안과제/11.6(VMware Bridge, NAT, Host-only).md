### **Host-only(Vmnet1)?**

Host-only방식은 외부 네트워크 연결 없이 Host-only 방식을 사용하는 Vmware끼리만 통신이 가능하다

### **NAT(Vmnet8)?**

Nat방식은 Vmware를 사용할 때, 가장 많이 사용하는 네트워크 방식이라고 생각한다

Nat방식을 사용하는 Vmware는 **IP를 Host PC에게서 할당**받는다 

그리고 Host PC는 공유기에서 IP를 할당받는다

### **Bridge(Vmnet0)**

Nat과 Bridge를 비교하자면 **IP를 어디서 할당받느냐**를 차이를 나눌 수 있다

Nat방식에서는 IP를 Host PC에게서 할당을 받았다면,

Bridge방식을 사용하는 Vmware는 IP를 공유기에게서 부여받는다

즉, 공유기가 Host PC와 가상머신에 같은 네트워크 대역의 IP를 각각 할당하기 때문에

Host PC와 가상머신은 **동일한 수준의 물리적 PC로 인식된다**