// rewritten by snowcat on 4/11/1997
// room: dongkou

inherit ROOM;

void create ()
{
  set ("short", "�Ž�����");
  set ("long", @LONG

��һ̧ͷ�����Ѿ�����һ���޴�Ķ��ڣ�������״����һ�����޵�
���졣���Ž����ιأ�������������

LONG);

  set("exits", ([
        "west" : __DIR__"cuiyun1",
        "east" : __DIR__"shimen",
      ]));
  set("outdoors", "firemount");

  setup();
}
