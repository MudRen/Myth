// created by snowcat.c 4/4/1997
// room: /d/nuerguo/townc1.c

inherit ROOM;

void create ()
{
  set ("short", "ɣ������");
  set ("long", @LONG

�������������ɣ����������������Ů������Ҫ��������
������������������ٶ���Ů�ˡ���������ߵ��ο�����
���������οͣ�Ů���Ƕ���ϲ��ӵ�Ͻ�ͷߴߴ������������
�����۸���ͣ��

LONG);

  set("exits", ([
        "north" : __DIR__"townb1",
        "east"  : __DIR__"townc2",
    ]));
  set("outdoors", __DIR__"");

  setup();
}






