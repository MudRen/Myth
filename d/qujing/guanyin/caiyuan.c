inherit ROOM;

void create ()
{
  set ("short", "��԰");
  set ("long", @LONG

������ƽʱ�ԵĲ˴��Ǵ���������ģ�����
������ƽʱ�����ֵĵط������ڻ���
����С�����ڸ���˽�ˮ�ء�
LONG);

 set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/seng" : 2,
        ]));
  set("exits", ([
          "west" : __DIR__"langdao3",
      ])); 

     setup();
}

