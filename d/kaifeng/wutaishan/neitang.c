

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
                
�������ڲ�û��ʲô���裬ֻ�Ǽ������һ��
�Ӷ��ѣ����е����ţ���������������λ���ˡ�
LONG);
  set("exits", ([
        "out" : __DIR__"xiaoyuan",
        
      ]));
	        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/pusa" : 1,
        ]));


  set("outdoors", __DIR__);

  setup();
  
}


