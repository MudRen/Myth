
#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
        object weapon;
        
        string *w_num,id;
        mapping skl;     
        
                w_num=({"weapon1","weapon2","weapon3","weapon4","weapon5",
                "weapon6","weapon7","weapon8","weapon9","weapon10",});
        
        if (me->is_busy())  
                return notify_fail("先忙完了你的事情再做这件事情吧！\n");  
        if (!me->query("new_weapons"))
          return notify_fail("你现在没有宝石新武器。\n");
         
        if (!arg && member_array(arg,w_num)==-1)
                          return notify_fail("你招回什么？。\n");
         id = me->query("id");
         skl=WSAVE_D->query_my_weapon(id); 
        if(undefinedp(skl[arg]))
          return notify_fail("你现在还没有升华这武器。\n");
        
       weapon= WSAVE_D->get_weapon(id,arg);
                  if (environment(weapon)==me)
                     return notify_fail("不是在你身上吗?\n");
         
                 
//         if (weapon->query("equipped"))  weapon->unwield();
         if (weapon->query("equipped")) {
           if( environment(weapon) && environment(weapon)->is_character()) weapon->unequip();
               else weapon->delete("equipped");
                                     }
             weapon->set("no_sell",1);
        if (weapon->move(me))
        {
        message_vision(HIY"\n    只听半空中一声龙吟，$n"HIY"从天而降,落入$N的怀中。\n\n"NOR,me,weapon);
        }else 
        {
        destruct(weapon);
        
        return notify_fail("召唤失败！\n"); 
        }

        me->start_busy(3);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式： zhaohui

这个指令让你可以召回你的宝石修炼武器。
HELP
 );
        return 1;
}

