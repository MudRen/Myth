// Room: /u/hkgroup/april
inherit ROOM;

void create ()
{
  set ("short", "�����ջ�");
  set ("long", @LONG

�����ڲ��ǣ��ײ��ǣ���Ҳ���ǣ��ͺ���è���·𣬼ȷǼ����ַ�Ұ��
����ʫҲ�У���Ҳ�У�����Ҳ�У��Զ����ϱ�ģ������Ϊ��Ʒ��Ҳ������

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"village",
]));
  set("outdoors", "/u/hkgroup");

  setup();
}
