// Room: /d/jjf/majuan.c

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG
�ؽ���һ�����й���ƥս�����������ȣ����ִ���ʦͽ����
�õ����ױ����ؽ���������ս����ȱ�����±�����ʬ��ɳ���ˡ�
��������Լ�����ƥս��������ĸ��顣����޵������쳣������
����ר���չˡ�
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xiaotong" : 1,
  __DIR__"npc/huangbiao" : 1,
  __DIR__"npc/hulei" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"front_yard",
]));
  set("out_doors", 1);

  setup();
}
