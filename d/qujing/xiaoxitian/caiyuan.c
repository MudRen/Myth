// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "��԰");
  set ("long", @LONG

��԰��ĵ��·��������Ÿ����߲˹Ϲ�����԰�ı�������һƬ
���������ϴ�����Ƥ���ӡ���԰�Ķ����Ǵ���Ժ���ϱ���һ��
ʯ����

LONG);

  set("exits", ([
        "northeast"   : __DIR__"siyuan",
        "south"   : __DIR__"chanfang",
      ]));
  set("outdoors", __DIR__);

  setup();
}



