//ROOM lianjianshi.c
inherit ROOM;

void create()
{
        set("short", "���̶");
        set("long",
                "�����������Ŷ��Ĵ���ֱ޵ĵط������ڱ�ѩ��ص���Ů���ϡ���Ȼ������\n"
                "��һ��Ư����̶ˮ���������˲��ò���̾����Ȼ�Ĺ��񹤡�̶������վ��һλ\n"
                "�������Ů�����а�����һ�ѿ��Ƽ��Ƿ�����ذ�ף������Ŀ��������̶ˮ����\n"
        );
        set("exits", ([
                "south" : "/d/moon/neartop",
        ]));

        set("objects",([__DIR__"npc/shibian" :1,]));

        setup();
        replace_program(ROOM);
}
