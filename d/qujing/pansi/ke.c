// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "�ͷ�");
  set ("long", @LONG

�ͷ���������Ϣ����ǽ��һ��ֽ����ɽ�����֮���Ӵ��⴫��
���������м��ѿ��Σ���ǽ��һС��������һͭ¯������ͨ��
�跿��

LONG);

  set("exits", ([
        "north"    : __DIR__"cha",
      ]));
  setup();
}

