inherit ROOM;

void create()
{
  set ("short", "�׻���");
  set ("long", @LONG

�������佫���ϳ�ǰ��Ϣ�ĵط������в����Ǻܴ󣬿�ǽ����
һ�����Σ�������һ�Ű����������в���豭����ɫ���ġ�ż
���м�����Ա���룬һ��������Ůһ���ź�
LONG);

        set("objects", ([
		__DIR__"npc/shinu": 1,
        ]) );

        set("exits",
        ([ /* sizeof() == 4 */
                "east" : "/d/huanggong/guangchang",
        ]));
	set("no_clean_up", 1);
        setup();
}

 

