// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

ɽ��˳ɽ���������£����ཧ�徰ɫ���ˡ���·���߻�������
���Ǵ��룬Գ�����Ұ¹̤��������̣�ԶԶ��ȥ���������
���������������������

LONG);

  set("exits", ([
        "southdown"    : __DIR__"shandao2",
        "southeast"    : __DIR__"qianhua",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

