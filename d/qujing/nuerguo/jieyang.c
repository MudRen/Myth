// rewritten by snowcat.c 4/4/1997
// room: /d/nuerguo/jieyang.c

inherit ROOM;

void create ()
{
  set ("short", "����ɽ");
  set ("long", @LONG

����ɽ��ʵֻ��һ��С���𡣲��������Ļ��ڽ���Ұ��������
����ȷ�ǲ���ɽ����һ���ۣ���Ϊ�������֡���ɽ������
��һ��С·��

LONG);

  set("exits", ([
    "north"   : __DIR__"sanchalu",
    "west"    : __DIR__"xiaolu1",
    "southup" : __DIR__"juxianan",
  ]));
  set("outdoors", __DIR__"");

  setup();
}






