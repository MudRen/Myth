inherit ROOM;

void create ()
{
  set ("short", "��Ӫ��");
  set ("long", @LONG

�����Ǳ�Ӫ���������ǹٱ�������ȥ���е����佫��ָ�����жӲ�
�����еĶ������������е����š�����������Ϣ����������������
������˧��������ɫ��Ѱ�������ܡ�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/city/qinglong-e4",
]));
  set("objects", ([ /* sizeof() == 3 */
  "/d/jjf/npc/fujiang" : 2,
  "/d/jjf/npc/chengyaojin" : 1,
]));

  setup();
}

