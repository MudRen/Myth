inherit ROOM;

void create ()
{
  set ("short", "��Ϣ��");
  set ("long", @LONG

��ǽ�ĵط���һ��һ�ŵĴ���������Ǻ�������
Ϣ�ĵط���
LONG);

 set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/seng" : 1,
        ]));
  set("exits", ([
         "down" : __DIR__"langdao3",
      ])); 

  setup();
}

