// snowcat moved to /d/qujing/wuji

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

ɽ����᫲�ƽ������ɽ�������������ƣ�����ʮ���ն�Ⱥ�ͻ��ƣ��ѱ�
�����ϱ�����紵�����е����˺�����
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : "/d/qujing/chechi/shatan3",
  "northeast" : __DIR__"shandao4",
]));

  setup();
}

