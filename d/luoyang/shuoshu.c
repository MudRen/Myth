inherit ROOM;

void create()
{
        set("short", "˵�����");
        set("long", @LONG
�������˵�������һλ��ʮ����������������ڴ���������������
��ҡͷ����˵����ͣ���������壬����������Ѧ�ٷ��ƣ������ƣ���Ӣ�ң�
���μǣ�ˮ䰴��ȵȣ���λ˵��������������ͨ����˵����Һ��ɡ���Χ
���������ǽ����ζ����ס�ĵ�ͷ�Ƶ���
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"chalou2",
        ]));
        set("objects", ([
                "/d/qujing/chechi/npc/shulao" : 1,
                "/obj/boss/luoyang_teahuoji" : 1,
                "/d/luoyang/npc/chake" : 3,
        ]));
        setup();
        replace_program(ROOM);
}

