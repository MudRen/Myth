// saiya.c stey 2001/12/30

#include <ansi.h>

int do_bian(object me);

int main(object me, string arg)
{
    string id;
    object obj,newob,*inv;
    int mana,spells,dmana,level,i;
    string str;

    seteuid(getuid());

    if( me->is_fighting() )
        return notify_fail("你正在战斗，无暇变身。\n");
    if( me->is_busy() || me->query_temp("pending/exercising"))
        return notify_fail("你正忙着呢，没工夫变身。\n");

    if (!arg && arg!="changedown" && arg!="changeup")
        return notify_fail("\n你必须使用zhenshens changedown(解除)或者zhenshens changeup(变身)？\n");



    if (arg=="changeup"){
        spells=me->query_skill("spells");
        mana=me->query("mana");
        level=me->query("level");
        if(me->query_temp("getdd/zhenshens")) return notify_fail("你已经是金刚护体不坏之身了。\n");
        if (spells<25)
            return notify_fail("你的法术不够。\n");

        if (mana<150)
            return notify_fail("你目前法力不够充盈。\n");
        if (level<50)
            return notify_fail("你的等级不够。\n");

        if (me->query_temp("zhenshens_time") && me->query_temp("zhenshens_time")+60 > time())
            return notify_fail("你现在气息不匀,等等吧。\n");



        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)  {
            if( inv[i]->query("zhanyisjsh")) {
                message_vision("突然间，$n化一道白光飞去，无影无踪！\n",me,inv[i]);
                destruct(inv[i]);
            }
        }
        if( !me->query("s_fayi") || !(newob=find_object(me->query("s_fayi"))))
            {
            newob = new("/obj/zhenshencloth");
            newob->set("owner_id", me->query("id"));
            newob->set("armor_prop/armor",level+65);
            newob->set("level",level+10);
            newob->set("armor_prop/spells", level/4);
            newob->set("zhanyisjsh", 1);
            }
        newob->move(this_player());
        newob->wear(me);
        me->set("s_fayi",file_name(newob));
        me->add_temp("apply/attack", level/4);
        me->add_temp("apply/damage",level/4);
        message_vision(HIY "$N心神宁静，席地而坐，口念咄咄咒语，头顶一缕浊气飘然而出．．．\n"
          +"\n只见$N全身发出阵阵声响，顿时天空云消雾散忽降五彩神光笼罩$N全身．．．．．．\n"
          +"\n$N此时精神为之一振，霎时间过往云烟似乎看的淡而无形．．．．．．\n\n" NOR,me);
        message("channel:rumor",HIG+"【"HIW"三界传说"HIG"】"HIC"弥勒佛"HIW"：据说"+me->query("name")+"破红尘，去杂念，超度真灵，修成不坏之体，并得到圣灵法衣。\n"+NOR,users());
        str=HIY"生界奇人"NOR+me->query("title");
        if (me->query("gender")=="女性") str+="女";
 
        me->set_temp("zhenshens_time",time());
        me->delete_temp("zhenshendown");
        me->set_temp("getdd/zhenshens",1);
    }

    if(arg=="changedown") {
        if (!me->query_temp("getdd/zhenshens"))
            return notify_fail("你没得到不坏之身，怎么能恢复原状？！\n");

        if (me->query_temp("zhenshendown"))
            return notify_fail("你已经恢复原状了。\n");
       
        me->set_temp("apply/attack",(me->query_temp("aplpy/atyack")-(level/4)));
        me->set_temp("apply/damage",(me->query_temp("aplpy/damage")-(level/4)));
       
        me->delete_temp("apply/short");
        me->delete_temp("apply/long");
        me->delete_temp("apply/name");
        me->set_temp("zhenshendown",1);
        if( newob=find_object(me->query("s_fayi")))
            {
            if (newob->query("equipped"))  newob->unequip();
            destruct(newob);
            }
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)  {
        
            if( inv[i]->query("id") =="shengling fayi") {
                message_vision(HIW"\n汝等小儿竟敢心怀杂念，乱我佛宗，收尔等法衣，示惩戒。\n"NOR,me,inv[i]);
                if (inv[i]->query("equipped"))  inv[i]->unequip();
                destruct(inv[i]);
            }
        }
        me->delete_temp("getdd/zhenshens");
        message_vision(HIY "\n$N受到如此惊吓，心神大乱．．．半天才恢复原状。\n" NOR,me);
        return 1;
    }
    return 1;
}



int help(object me)
{
    write(@HELP

指令格式 ： Zhenshens changeup (炼真身，做世间完人)
            Zhenshen changedown (破己真身，复常态)
相关指令:     Quit
破红尘，去杂念，超度真身，还要取决于自身的法力修为和自身平时积累的德行修行。



HELP
    );
    return 1;
}


