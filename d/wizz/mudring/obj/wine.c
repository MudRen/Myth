// cigarette.c

#include <ansi.h>

inherit ITEM;

void init()
{
//  9          add_action("do_drink", "hebei");
          add_action("do_drink", "he");
}

void create()
{
        string *order = ({MAG"�������"NOR,HIR"Ѫ������"NOR, HIC"������԰"NOR, HIW"�׷���"NOR, HIY"����������"NOR, HIB"������ʿ"NOR, 
HIG"ʮһ�µĺ���"NOR, HIM"��ɫ����ĩ"NOR});
        set_name( (order[random(sizeof(order))]), ({ "booze", "wine" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��ɫ�����˵ļ�β�ƣ����̲�ס�����ȥ(he)��\n");
                set("unit", "��");
                set("count",8);
                set("value", 50000);
        }
}


int do_drink()
{
        object me = this_player();
        object obj = this_object();

/*
        if(environment(me)->query("sleep_room"))
                return notify_fail("����˯����Ⱦƣ�\n");
*/
        if(environment(obj) != me)
                return notify_fail("�����Ɑ�ƺ�������ɣ�\n");
        if(query("master") && query("master") != me->query("id"))
                return notify_fail("��ɲ�����ľƱ������ô��ˡ�\n");
        add("count",-1);
        me->start_busy(1);
        me->add("combat_exp", 5);
        switch(query("count")) {
                case 1: message_vision("$N�������һ�ھƣ����������ͨ�졣\n", me);
                        break; 
                case 2: message_vision("$Nб���������ϣ����ű�����ʣ�µ�һ��ƿ�ʼ�����¡�\n", me);
                        break;
                case 3: message_vision("$N�ֺ���һ�ڣ�ͻȻ�о��������´��ĵ׷���\n", me, obj);
                        break;
                case 4: message_vision("$N���������￪ʼ΢΢�ط��ȣ����ɵسԳ�Ц��������\n", me, obj);
                        break;
                case 5: message_vision("$N�ѺȽ�����ľƺ������ϸϸ��Ʒ����һ��ź�����ȥ��\n", me, obj );
                        break;
                case 6: message_vision("$N���žƱ��ߵ���ǰ�����Ŵ���ľ�ɫ��\n", me, obj);
                        break;
                case 7: message_vision("$N���žƱ��ߵ���ǰ�����Ŵ���ĳ�Ⱥ��MM,������������,����������һ�ء�\n", me, obj);
                        break;
                case 8: set("master", me->query("id"));
                        message_vision("$N����$n�����ɵ�Ϊ��������ɫ����������\n", me, obj);
                        break;
                default:
                        break;
        }        
        if(query("count") > 1) call_out("do_drink", 10);
        else destruct(obj);
        return 1;
}

