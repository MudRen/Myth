//����-����

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
        set_name(HIW"����-����"NOR,({ "jue sword", "sword", "jian" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100);
                set("rigidity", 10);
                set("sharpness", 10);
                set("unique", 1);
                set("material", "steel");
                set("weapon_prop/dodge", 10);
                set("weapon_prop/parry", 10);
                set("treasure",1);              
                set("no_sell",1);              
                set("long", "һ������Ϊ������񽣡�\n"); 
                set("wield_msg", "\n");
                set("unwield_msg", "\n$N��$n����һֱ����ʱ������ӿ��ɲ�Ǽ�$n��ʧ����Ӱ���٣�\n");
        }
        init_sword(240);
        setup();
}

int wield()
{
        object ob = environment();
        object me = this_object();
        mapping weapon_prop;
        object *obj, *inv, weapon;
        int ret, i, j;
        if (ob->query("combat_exp") < 100000 
            || ob->query_str() < 20 || ob->query("max_force") < 1000 
            || ob->query("force") < 1000){
                message_vision(HIY"$N���ָոմ�����$n�Ľ�����ͻȻһ�������Խ��д�������$N������Զ��$nҲ��֮������ϡ�\n"NOR, ob, me);
                ob->receive_damage("qi", 100);
                ob->receive_wound("qi", 100);
                me->move(environment(ob));
                return 0;
                }
       else if (ret=::wield()){
           message_vision(HIW"\n����$Nһ����߳�����к��������������绮����ʵ����磬��������ȴ�����Ե����ƣ�\n\n"NOR, ob, me);
           ob->add("force", -200);
           obj = all_inventory(environment(ob));
           if(sizeof(obj) > 1)
               message_vision(HIC"��Ȼ��������������֮���׷��Զ�Ծ��������$N��ǰ�ĵ��ϣ�����ָ�죡\n"NOR, ob);
           for(i=0; i<sizeof(obj); i++) {
                if(obj[i]==ob ) continue;
                inv = all_inventory(obj[i]);
                for(j= 0;j< sizeof(inv);j++){
                       if(!mapp(weapon_prop = inv[j]->query("weapon_prop"))) continue;        
                       if(inv[j]->query("skill_type")!="sword") continue;
                       if(inv[j]->query("equipped")){
                          if(obj[i]->query("force") > 1000){
                             obj[i]->add("force", -100);
                             tell_object(obj[i], HIW"���������֮"+inv[j]->name()+HIW"�������𶯣��Ҷ���˫�ֽ��գ���û�������ɳ���\n"NOR);
                             continue;  
                             }
                           else {
                                tell_object(obj[i], HIW"���������֮"+inv[j]->name()+HIW"�������𶯣�����ղ�ס����Ȼ���ַɳ���\n"NOR);
                                tell_room(environment(ob), YEL+obj[i]->name()+"һ�����ղ�ס������"+inv[j]->name()+YEL"��Ȼ���ַɳ���\n"NOR,({ obj[i] }));
                                }
                           }
                       inv[j]->move(environment(ob));
                       }
           }
           return ret;
       }
}

