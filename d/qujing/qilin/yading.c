// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "�¶�");
  set ("long", @LONG

������ɽ�괦һ��͹������£��Ĵ�������ɽ�������ʣ�ɽ�޺��
����Ȼ�����������ٹ�һ��콹һƬ����Զ����һС�£�������
����ɳ��

LONG);

  set("exits", ([ 
    "westup" : __DIR__"dongkou",
    "southeast" : __DIR__"shankou",
  ]));
  set("outdoors", __DIR__"");
  setup();
}

