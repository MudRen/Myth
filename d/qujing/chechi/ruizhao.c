// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/ruizhao.c

inherit ROOM;

void create ()
{
  set ("short", "���׳�");
  set ("long", @LONG

һ����ϸש�̾͵�С�㳡������Χ����һȦ�����������ȱˮ��
ľ�Ѿ���Щ�ɿ��ˡ������ǳ��ٹ���������֮һ��������������
���ﲻ����

LONG);

  set("exits", ([
        "east"         : __DIR__"dongmen",
        "south"        : __DIR__"jieshi7",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

