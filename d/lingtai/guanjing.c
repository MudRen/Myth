// Room: some place in ��ţ����
// guanjing.c

inherit ROOM;

void create()
{
        set ("short", "�۾�̨");
        set ("long", @LONG

��������һ�����£��䲻������ǧ�ߣ�ȴҲ�Ƕ����쳣����Χ��
��Щľ׮�����������Է�ʧ�㡣Զ���������߼���һƬһƬ��
���߷������������͵�����֮�У������Կ���һЩũ����������
�ɻ
LONG);
        set("exits", ([ /* sizeof() == 4 */
                "west" : __DIR__"uphill4",
        ]));
        set("objects", ([ /* sizeof() == 2 */
                "/d/lingtai/npc/zhangdaoling" : 1,
                "/d/sea/npc/beast/beast1" : 1,

        ]));

        set("outdoors", 1);
        setup();
}

