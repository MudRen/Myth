//Cracked by Roath

inherit BANK;

void create ()
{
  set ("short", "���Ǯׯ");
  set ("long", @LONG

���Ǯׯ��������һ�������ƣ������Ǯׯ��������������һ���߸�
����ľ��̨�����ϰ���һ�����������ڹ�̨�Ͻ��ʡ�Ǯׯ������ǽͷ
����һ��(bian)�������Ǵ��ţ�ͨ��˴����֡�

LONG);

  set("item_desc", ([
    "bian": @TEXT

�ͻ������ڱ�Ǯׯ��

account         ���ʡ�
deposit         ��
withdraw        ȡ�
convert         �һ�Ǯ�ҡ�

TEXT
  ]) );

  set("exits", ([
    "east" : __DIR__"shun4",
  ]));

  set("objects",  ([
    __DIR__"npc/yang" : 1,
  ]));

  set("no_clean_up", 0);
  setup();
}


