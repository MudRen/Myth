// created by snowcat.c 4/4/1997
// room: /d/nuerguo/townb1.c

inherit ROOM;

void create ()
{
  set ("short", "��Ů����");
  set ("long", @LONG

������������Ķ�Ů������Ů�����ڽ�ͷ����ɹ̫�����е�
���ḾŮ����ӭ���������ο���Ц�����ش��к���Ů��Ⱥ��
��ʱ�ر�������Ц��

LONG);

  set("exits", ([
        "north" : __DIR__"towna1",
        "east"  : __DIR__"townb2",
        "south" : __DIR__"townc1",
    ]));
  set("outdoors", __DIR__"");

  set("objects", ([
         __DIR__"npc/woman1" : 3,
     ]));

  setup();
}






