// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

ɽ·��Ϊ����ն���������һ��ͻأ����ʯ�ڶ��ͣ�Զ��
���͵ĺ����϶������ش���������Ұ�ַ紵�ݶ�������ë���
Ȼ�����������˽Ų���

LONG);

  set("exits", ([
        "southdown"   : __DIR__"shanlu6",
        "northup"   : __DIR__"shanlu1",
      ]));
  set("outdoors", __DIR__);

  setup();
}



