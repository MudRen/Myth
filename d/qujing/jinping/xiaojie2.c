// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С��");
  set ("long", @LONG

���������ϵĽֿڣ������ɼ�һ���������ʯ�����̳ɵ�С
���ϣ����˾���������������ͷ�д�������Ʈ��������ζ��
��Զ�������Ҽһ������׵����������д��˼�ե���͵Ĵ���
ζ��

LONG);

  set("exits", ([
"north"   : __DIR__"qiaonan",
"west"   : __DIR__"fenju",
        "east"   : __DIR__"jimiao",
        "south"   : __DIR__"xiaojie4",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



