// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��·");
  set ("long", @LONG

��ƮƮ����������һ�ۼ�Ŀ��ȥֻ��ũ������ģ�����С����
������ǵ�㡣�����Ǻ�ʵ������·���������﹡����ʱ����
����Ϫˮ�ڹ���������

LONG);

  set("exits", ([
        "north"   : "/d/qujing/qinglong/shanlu7",
        "west"   : "/d/qujing/tianzhu/shan5",
        "southeast"   : __DIR__"cunlu2",
      ]));
  set("outdoors", __DIR__);

  setup();
}



