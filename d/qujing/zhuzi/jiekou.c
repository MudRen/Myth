// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "�ֿ�");
  set ("long", @LONG

���ﱱϼ�������Ͻֽ��棬·�ڷ����������������ϡ���������Զ
Զ���������ţ�����ͨ�����Ϲ��ĳ����Ĺ�¥���������߸���ͨ��
��ϼ�֡�

LONG);

  set("exits", ([ 
    "north" : __DIR__"zhuzi2",
    "south" : __DIR__"zhuzi3",
    "west" : __DIR__"beixia3",
    "east" : __DIR__"beixia4",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
