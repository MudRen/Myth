inherit ITEM;

#include <ansi.h>
void create()
{
        set_name(HIW"ˮ����"NOR, ({"ball"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "����һ��ˮ����\n");
                set("unit", "��");
                set("value", 0);
        }
        setup();
}
void init()
{
        add_action("do_zhanbu", "zhanbu");
}

int do_zhanbu(string arg)
{
        object ob, zhanbu, *ob_list;
        object me = this_player();
        int i;
        if (!arg)
        return notify_fail("ָ���ʽ��zhanbu <����>\n"); 
/*
        if( (int)me->query_skill("zhanbushu", 1) < 150 )
        return notify_fail("���ռ�����������ߣ��޷�ʹ��ˮ�������ָ߼�����\n");
*/

        message_vision(BLU"$N������ָ�������ӡ�������î�������ȡ��硢δ���ꡢ�ϡ��硢���ķ�λ����ϸ�������š�����\n"NOR, me);
        ob = find_player(arg);
        if( !ob ) ob = find_living(arg);
        if( !ob || !me->visible(ob)) {
                arg = resolve_path(me->query("cwd"), arg);
                ob_list = children(arg);
                for(i=0; i<sizeof(ob_list); i++) {
                        if( !ob = environment(ob_list[i]) ) continue;
                        printf("%O\n", ob );
                }
                return 1;
        } 
        if (!ob) return notify_fail("����û�����.\n");
        zhanbu = environment(ob);
        if (!zhanbu) return notify_fail("����˲�֪��������Ү...\n");
        printf(HIW"����ָ���%s(%s)���ں�����%s"NOR+HIW"һ�����\n"NOR,
                (string)ob->name(),
                (string)ob->query("id"),
                (string)zhanbu->query("short"));
        if( random((int)ob->query("combat_exp", 1 ) / 2) < (int)me->query("combat_exp", 1)) {
        if(random(10) > 5 ) {
        tell_object(ob, HIY"ڤڤ������ú����������ڿ�̽�����ڵķ�λ��\n"NOR);
        }
        else {
        write("\n"); }
        }
        return 1;
        
}

