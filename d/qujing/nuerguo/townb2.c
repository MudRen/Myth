// created by snowcat.c 4/4/1997
// room: /d/nuerguo/townb2.c

inherit ROOM;

void create ()
{
  set ("short", "��Ů����");
  set ("long", @LONG

������������Ķ�Ů���С�Ů�����ڽ�ͷ����ɹ̫�����е�
���ḾŮ����ӭ���������ο���Ц�����ش��к���Ů��Ⱥ��
��ʱ�ر�������Ц��

LONG);

  set("exits", ([
        "north" : __DIR__"towna2",
        "east"  : __DIR__"townb3",
        "west"  : __DIR__"townb1",
        "south" : __DIR__"townc2",
    ]));
  set("outdoors", __DIR__"");

  set("objects", ([
         __DIR__"npc/woman1" : 3,
         __DIR__"npc/woman2" : 3,
     ]));

  setup();
}






