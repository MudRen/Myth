inherit ROOM;

void create ()
{
  set ("short", "�ȵ�");
  set ("long", @LONG

���ȵ�����վ���������ȶ�������յ���
�ƻ�������ǰ����·��
LONG);

 set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/seng" : 1,
        ]));
  set("exits", ([
           "east" : __DIR__"caiyuan",
          "west" : __DIR__"fangzhang",
         "up" : __DIR__"xiuxi",
        "north" : __DIR__"jingge",
        "south" : __DIR__"langdao2",
      ])); 

  setup();
}

