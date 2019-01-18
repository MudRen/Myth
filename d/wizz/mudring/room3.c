// sheshenya.c
// ������

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",MAG "�ù�̨������" NOR);
        set("long",@long
�������ֳ����������ǿ��ճ����ƺ�����⡢���֮�ء�̨���������ɣ�
�����޵ף��������ڡ���Ŀ��������������Ĵ�Сѩɽ��������Ŀ����Ϊ����
�������࣬�������棬���������ã�������������Ͷ���ƺ��������������
long);
        set("outdoors", "����ɽ");
        set("exits",([
                "east" : __DIR__"room3",

]));
        setup();
}

void init()
{
        add_action("do_jump", "jump");
        add_action("do_look", "look");
}

int do_look()
{
        object me = this_player();
        mixed *local;
        local = localtime(time() * 60);
        if(local[2] < 4 || local[2] >= 21) {
        write(BLU"�������º�����һƬ���������ֳ�һ�㡢�������ɫ�����⣬��������\n"
                            "Խ��Խ�࣬ת�۱㲼��ɽ�ȣ��е�����өƮ�ɣ��е��緱����˸��\n"NOR, me);
        }
        if(local[2] >= 4 && local[2] < 8)  {
        write(HIR"�����Ǹո�����һ����΢�׵Ĺ��ڶ����Ʋ����֣�һ�ֺ����е�������\n"
                            "��ǧ�����ʱ�ڲ���ӳ���³��ֳ�����������\n"NOR, me);
        }
        if(local[2] >= 8 && local[2] <= 13) {
        write(HIC"���ƺ�������ãã��������Ұ��Զ����ʡ��ƺ��ᵴʱ�����ڽ𶥣���\n"
                            "̤���ƣ�����ƮƮ����֮�У�������Ѹ��ӿ��ʱ�������𶥶�������ǰ������\n"
                            "�����г�������֮�⡣\n"NOR, me);
        }
        if(local[2] > 13 && local[2] < 14) {
        write(YEL"�����羲���ƺ�ƽ�̣������Լ���������㱳��б��������������������\n"
                            "�ɲ�ɫ�⻷��������Լ�����Ӱ�����س�������ɫ�����ϡ����⻷���˶���\n"
                            "��Ӱ�ڻ��С������������ġ�����������������������������������\n"
                            "������һ��ʹ������ĳ������������㲻����Ҫ�ڴ�Ͷ���ƺ�����������\n"
                            "�����ۣ�������ӡ�\n"NOR, me);
        }
        if(local[2] >= 14 && local[2] < 21) {
        write(HIC"���ƺ�������ãã��������Ұ��Զ����ʡ��ƺ��ᵴʱ�����ڽ𶥣���\n"
                            "̤���ƣ�����ƮƮ����֮�У�������Ѹ��ӿ��ʱ�������𶥶�������ǰ������\n"
                            "�����г�������֮�⡣\n"NOR, me);
        }
}

int do_jump(string arg)
{
        object me = this_player();
        mixed *local;
        local = localtime(time() * 60);
        
        if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���ģ�\n");

        if(!arg || arg == "" || arg != "cliff")
        return notify_fail("��Ҫ����������\n");

        if(arg == "cliff") {
        if(local[2] > 13 && local[2] < 14 ) {
        if( (int)me->query("kar",1) > 28 && (int)me->query("dex", 1) > 28 && random(4) > 2 )  
        {
        message_vision(HIR"$N�������������¡�\n"NOR, me);
        me->move(__DIR__"bankong");
        call_out("do_wait", 2, me);
        return 1; }
        
        else {
        message_vision(HIR"$N�������������¡�\n"NOR, me);
        me->move(__DIR__"bankong");
        call_out("do_wait1", 2, me);
        return 1; } return 1;
        }
        else {
        message_vision(HIR"$N�������������¡�\n"NOR, me);
        me->move(__DIR__"bankong");
        call_out("do_wait2", 2, me);
        return 1; }
        }
} 

void do_wait()
{
        object me = this_player();
        write(HIR"��ֻ���ö��ߺ����������죬����ɿ������׺ȥ....\n"NOR, me);
        write("ͻȻ�㱻ʲô�����赲��һ��........\n", me);
        me->move(__DIR__"wanniansong");
        me->unconcious();
}

void do_wait1()
{
       object me, *ob, *inv;
       int i, j;
       me = this_player();
       ob = all_inventory(environment(me));
        write(HIR"��ֻ���ö��ߺ����������죬����ɿ������׺ȥ....\n"NOR, me);
        me->move(__DIR__"shuitan");
        write(HIC"ֻ������ͨһ�����������һ����ˮ̶�У���ཹ�ེ��˺ü���ˮ....\n"NOR, me);
        for(i=0; i<sizeof(ob); i++) {
            inv = all_inventory(ob[i]);
            for (j = 0; j < sizeof(inv); j++)
            destruct(inv[j]);
            ob[i]->unconcious();
        me->set("water", 666); }
}

void do_wait2()
{
        object me, tmp;
        object *ob;
        int i;
        me = this_player();
        write(HIR"��ֻ���ö��ߺ����������죬����ɿ������׺ȥ....\n"NOR, me);
        write(HIW"��ֻ����������������Զȥ........\n"NOR, me);
        me->move(__DIR__"shuitan");
        me->set_temp("last_damage_from","ˤ��ɽ�µ�");
        me->unconcious();
        me->die();
                if (tmp = present("corpse", this_object())) {
                        ob = deep_inventory(tmp);
                        i = sizeof(ob);
                        while (i--) if (userp(ob[i])) ob[i]->move(this_object());
                        destruct(ob[i]);
                        destruct(tmp);
                        destruct("corpse");
                        if (me) tell_room(this_object(), me->name()+"��ʬ�Ƕ��Ҳ����ˡ�\n");
                }
                
}

