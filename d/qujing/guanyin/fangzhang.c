inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�����Ƿ���ƽʱѧϰ�𷨵ĵط��������������
���顣
LONG);

        set("objects", 
        ([ //sizeof() == 3
                __DIR__"npc/yuanzhu" : 1,
                __DIR__"npc/guangzhi" : 1,
        ]));
  set("exits", ([
         "east" : __DIR__"langdao3",
      ])); 

  setup();
}

