// Room: some place in ��ţ����
// jingge.c

inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

����������Ƕ��ؾ��󣬵����沢û�ж����顣ֻ��һЩ������
���һЩ���̾��乩������ƽʱ�ж���һ���ŵ��������İ���
���С�
LONG);
set("item_desc",(["shelf": 
"Զ���Ŀ�������������һ���Ϻ�����Щǧ���ģ����¾�֮�࣮\n"]));
set("exits", ([ /* sizeof() == 4 */
"south": __DIR__"houyuan",
"up": __DIR__"lou",
]));
set("objects", ([
                __DIR__"npc/guangxi": 1 ]) );
        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "up" ) {
        if (objectp(present("guang xizi", environment(me)))) {
        if((string)me->query("family/family_name")=="����ɽ���Ƕ�") {
        return ::valid_leave(me, dir);
        }
        return notify_fail("�����Ӷ���˵�����������ҵ��ҵ�������֮�أ������Ҵ���\n");
        }
        }
        return ::valid_leave(me, dir);
}



