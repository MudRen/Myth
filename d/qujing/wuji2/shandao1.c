// snowcat moved to /d/qujing/wuji

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

ɽ����᫲�ƽ������ɽ�������������ƣ�����ʮ���ն�Ⱥ
�ͻ��ƣ��ѱ涫���ϱ�����紵�����е����˺�����

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "northeast" : "/d/qujing/pingding/shan4",
    "southwest" : __DIR__"shandao2",
  ]));
  set("outdoors", __DIR__"");

  setup();
}

