inherit ROOM;

void create()
{
        set("short", "��̨");
        set("long", @LONG
������ϷԺ�ĺ�̨���ط����󣬳��˻�ױ̨����û��ʲô�ˣ�������
�����˷�װ�͵��ߣ��Եúܽ��գ����˶����ŵ�æµ�ţ���ױ�Ļ�ױ��ж
ױ��жױ���޵��ߵ��޵��ߣ����װ�����װ����Ҷ���Ϊǰ̨�ı�����
��׼����
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"xiyuan",
        ]));
        set("objects", ([
                "/d/qujing/chechi/npc/xizi" : 2,
        ]));
        setup();
        replace_program(ROOM);
}

