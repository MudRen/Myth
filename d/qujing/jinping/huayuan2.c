// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��԰");
  set ("long", @LONG

һ����ͤ�ڻ�԰����С������ؽ��ţ�������С����������һ
Ƭ��һƬ�Ļ��ԣ�����ĵ����ҩ������÷�ջ��ȵȡ����Եĺ�
����Կ���һ��Ƭ��԰�������ʵ���ۡ�

LONG);

  set("exits", ([
        "west"   : __DIR__"huayuan1",
        "south"   : __DIR__"huayuan3",
      ]));
  set("outdoors", __DIR__);

  setup();
}



