// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "�ٽ�ɽ´");
  set ("long", @LONG

ɽ��Ũ�ܺ�ѹѹ�������ɽ·����ɽ�����ѣ�����������ƽ��
��Ũ�ܵ�ɽ����żȻ������Ұ��ԶԶ�ĺ�У�·�߷紵�ݶ�ɳ
ɳ���졣

LONG);

  set("exits", ([
        "northeast"   : __DIR__"shan4",
        "southwest"   : __DIR__"shanmen",
      ]));
  set("outdoors", __DIR__);

  setup();
}



