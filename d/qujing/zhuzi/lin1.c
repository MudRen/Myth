// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "����·");
  set ("long", @LONG

�����ڳ���������·�ϣ������������ģ���紵��Ҷ��֦�裬ʱ��
ʱ����Զ���Ļ�ХԳ�䡣���˲��������ؼӿ첽����

LONG);

  set("exits", ([ 
    "northeast" : "/d/qujing/xiaoxitian/lindao7",
    "southeast" : __DIR__"lin2",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
