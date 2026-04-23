# NBC LGI Container-SmartPointer

* 조작방법
    * I - 인벤토리 열기/ 닫기

* Item
    * Item_1
            * 남은 개수가 특정 값(3)이 되었을 때 Item_2 추가
            * 전량 사용 시 칭호 획득
    
    * Item_2
        * Item_1과 다른 값
        * 특정 칭호가 있어야만 사용 가능
    
    * InventoryManager
        * 시작 시 Item_1 획득
        * Item 탐색
        * 아이템의 사용 여부 결정
            * 유효한 값인지
            * 개수가 충분한지
            * 요구하는 칭호가 있는지
        * 아이템의 추가/삭제 관리

* UI
    * WBP_Inventory
        * 생성 시 인벤토리 초기화 및 Inventory을 순회하여 WBP_Item추가
        * WBP_Item의 버튼 클릭을 감지해 아이템 사용
            * 사용 이후 인벤토리 갱신

## Youtube 영상

[Youtube 링크](https://youtu.be/ykL-U0QCDgU)