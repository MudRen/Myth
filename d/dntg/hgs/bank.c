// Room: /d/4world/bank.c
inherit BANK;

void create ()
{
  set ("short", "�ż�Ǯׯ");
  set ("long", @LONG

�ż�Ǯׯ�������ǳ����׸�����������﹫��Ҳ���н��顣��
���侭Ӫ�з�����·�ֹ㣬Ǯׯ������Ҳ�ǲ������к��һ��
�߳߹�̨��̨ǰ�и�С����(paizi)������վ��λ��������������
LONG);
        set("item_desc", ([
                "paizi": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�

account         ���ʡ�
deposit         ��
withdraw        ȡ�
convert         �һ�Ǯ�ҡ�
TEXT

]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"north2",
]));

  setup();
}
