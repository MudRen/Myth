// Room: some place in ��ţ����
// room.c

inherit ROOM;

void create()
{
        set ("short", "��̨");
        set ("long", @LONG

һ����̨�߸����ϣ�����������ʦ������̨�ϣ���������ʮ��С
������̨�¡���Χ����ȫ���ɼ����ߣ���һ��˵��������ͣ���
͸��ׯ�ϡ�
LONG);
        set("exits", ([ /* sizeof() == 4 */
                "out": __DIR__"houlang5",
        ]));
        set("objects", ([
                __DIR__"npc/puti": 1 ]) );
        set("no_clean_up", 0);
        setup();
}

