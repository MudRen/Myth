inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������С������ƽʱ��ѧϰ�ĵط�����������ڷ���
���������š�
LONG);

  set("exits", ([
        "south" : __DIR__"langdao3",
      ])); 
        set("objects", 
        ([ //sizeof() == 3
                __DIR__"npc/guangmou" : 1,
        ]));

  setup();
}

