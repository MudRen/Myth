// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "é��");
  set ("long", @LONG

é�����е�ڰ�����ǽ����һ��ľ���ӣ�����һյͭ�͵ơ���
ǰ��һˮ��ʢ�Ű����Ϫˮ��������һ��ݵ��Ӵ�������һ��
��ë̺��

LONG);

  set("exits", ([
        "west"    : __DIR__"zhuang",
        "southwest"    : __DIR__"yang5",
      ]));
  set("resource", ([
        "water"   : 1,
      ]));
  setup();
}

