// sanqingdian.c �����
//lpg 19991005

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
���������������������䵱�ɻ�͵ĵص㡣����Ԫʼ����̫�ϵ�
���������Ͼ��������㰸���������ơ���ǽ���ż���̫ʦ�Σ����Ϸ��ż�
�����š��������������ȣ�����������Ĺ㳡���ϱ��Ǻ�Ժ��
LONG );
        set("valid_startroom", 1);
        set("exits", ([
                "north" : __DIR__"guangchang",
                "south" : __DIR__"houyuan",
                "east"  : __DIR__"donglang1",
                "west"  : __DIR__"xilang",
        ]));
        set("objects", ([
           __DIR__"npc/wulei": 1,
           __DIR__"npc/mingyue": 1,
        ]));
//        set("no_clean_up", 0);
        setup();
}
