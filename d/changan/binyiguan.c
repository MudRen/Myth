inherit ROOM;
void create()
{
set("short", "���ǹ�");
set("long", "
    ��������������������֮���飬�ҹ���ʷ�Ϻ�������������и��ְ������ߵİ취������\n
��Ҫ�İ취������ͻ��ᣬ������������㡣��������ռ�ø��أ��˷�ľ�ģ������ҹ������⽨\n
ͳ�ν׼��Ѻ����ɥ�����񷨣� ��ʹ����ͥ��Ϊ�������߶������Ʋ��ľ��ء�ʵ�л��ᣬ��\n
ռ�ø��أ�����Ҫ��ľ�����Խ�ʡװ�������ķ��ã�Ҳ�ް��ڶ����ߵļ��\n
    Ϊ�������߾����������������������������ʬ��𻯣�shao���ɣ�\n
");
set("exits", ([ /* sizeof() == 4 */
"east" : __DIR__"broadway1",
]));
// mudring Dec/09/2002
set("no_fight",1);
set("no_move",1);
setup();
}
void init()
{
add_action("do_burn","shao");
}
int do_burn(string arg)
{
object me;
object tar;
int score, pot;
me = this_player();
score = (int) me->query("combat_exp");
pot = (int) me->query("potential");
// busy cant shao
// mudring Dec/09/2002
if (me->is_busy())
return notify_fail("�𼱣��𼱡�\n");
if( !arg || arg == "") 
return notify_fail("��Ҫ��ʲô��\n");
tar = present(arg, me);
if( !tar) 
return notify_fail("û�����ʬ�壮\n");
if( userp(tar))
return notify_fail("���ʲô�����о�ѽ��\n");
if( tar->query("owner"))
return notify_fail("�ⶫ�����ﲻ�գ�\n");
if( tar->is_corpse())           
{
me->add("combat_exp", 10);
me->add("potential", 10);
message_vision("$N��$n����¯�ţ�$n�����Ŀ�ʼȼ�գ������һ�ѹǻң�\n", me, tar);
// �������busy�ĸ�busy??
// mudring Dec/09/2002
message_vision("$N��������ǰ�����ӣ����ﲻ��ӿ������������\n", me);
me->start_busy(5);
}
message_vision("$n�ջ��ˣ�\n", me, tar);
tar->move(environment(me));
destruct(tar);
return 1;
}

