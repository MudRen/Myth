// created by snowcat.c 4/4/1997
// room: /d/nuerguo/townb3.c

inherit ROOM;

void create ()
{
  set ("short", "��Ů�ﶫ");
  set ("long", @LONG

������������Ķ�Ů�ﶫ��Ů�����ڽ�ͷ����ɹ̫�����е�
���ḾŮ����ӭ���������ο���Ц�����ش��к���Ů��Ⱥ��
��ʱ�ر�������Ц��

LONG);

  set("exits", ([
        "north" : __DIR__"towna3",
        "west"  : __DIR__"townb2",
        "south" : __DIR__"townc3",
    ]));
  set("outdoors", __DIR__"");

  set("objects", ([
         __DIR__"npc/woman1" : 5,
     ]));

  setup();
}






