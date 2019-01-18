#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_DBASE;



int main(object me, string arg)
{



        object baoshi,weapon;
        int i,k,ppl,j;
        string bshi,wes,*w_num,*kw,id,wes_file,save_file;
        mapping skl;


return 0;
        if (! arg )
                return notify_fail("你要合并什么物品？\n");

        if (sscanf(arg,"%s at %s",bshi,wes)!=2)
                return notify_fail("你要升华什么宝石在什么武器？<指令>:shenghua xxx at xxx \n");


        if (me->is_busy())
                return notify_fail("先忙完了你的事情再做这件事情吧！\n");

        if (me->is_fighting())
                return notify_fail("你现在正在打架，没时间做这些事情。\n");
        if (!( baoshi=present (bshi,me)))
                return notify_fail("你身上没有这个物品。\n");
        if (!( weapon=present (wes,me)))
                return notify_fail("你身上没有这个武器。\n");
        if (!(i=(int)baoshi->query("b_lvl")) || i < 21)
                return notify_fail("你身上这个宝石级别不能升华。\n");
        if( !weapon->query("weapon_prop") )
                return notify_fail("你只能升华可当作武器的东西。\n");
        if( ( weapon->query_unique() && !weapon->query("fabao"))
            || weapon->query("weapon")
            || weapon->query("unique")
            || weapon->query("weapon")

            )
                  return notify_fail("这件武器不能进行宝石升华。\n");
        if (weapon->query("owner_id") && weapon->query("owner_id")!=me->query("id"))
                  return notify_fail("这件武器不是你的，不能进行宝石升华。\n");
         if (weapon->query("equipped"))    return notify_fail("你必须先放下你的武器。\n");
        if (me->query("max_sen") < 1500)
                return notify_fail("你现在的精力修为有限，无"
                                   "法施展如此艰深的法力。\n");

        if (me->query("sen") < 1000)
                return notify_fail("你现在精神不济，无法施展法力。\n");
        if(  weapon->query_unique() && weapon->query("fabao"))
           {
           WEAPON_D->update_baoshi(weapon,i,i%7);
        weapon->save();
                   message_vision(HIM "$N" HIM "将"+baoshi->name()+"和"+
                   weapon->name()+"摆在一起，默运神通使它们变化。\n"+
                   weapon->name()+"发出耀眼的光芒，宝石随之钻入消失了！\n" NOR, me);
                   destruct(baoshi);
            return 1;
             }
        w_num=({"weapon1","weapon2","weapon3","weapon4","weapon5",
                "weapon6","weapon7","weapon8","weapon9","weapon10",});
        id=me->query("id");

        if (!me->query("new_weapons"))
           {
            WEAPON_D->update_baoshi(weapon,i,i%7);
            WSAVE_D->set_save_file(me,weapon,w_num[0]);
            WSAVE_D->record_weapon(me,weapon,w_num[0]);
            me->set("new_weapons/main",w_num[0]);
              message_vision(HIM "$N" HIM "将"+baoshi->name()+"和"+
               weapon->name()+"摆在一起，默运神通使它们变化。\n"+
                   weapon->name()+"发出耀眼的光芒，宝石随之钻入消失了！\n" NOR, me);
                   weapon->set("no_sell",1);
                       destruct(baoshi);
            return 1;
            }

            skl=WSAVE_D->query_my_weapon(id);
            wes_file=base_name(weapon);
            kw=({});
            ppl=-1;j=0;
            for(k=0;k<sizeof(w_num);k++)
            {
               if(undefinedp(skl[w_num[k]]))
                 { kw +=({w_num[k]});
                   j++;
                   continue;
                   }
                if(skl[w_num[k]]["file"]==wes_file)
                  ppl=k;

             }
            if(ppl!=-1)
            {

                WSAVE_D->set_settings(weapon,id,w_num[ppl]);


                WEAPON_D->update_baoshi(weapon,i,i%7);
                WSAVE_D->record_weapon(me,weapon,w_num[ppl]);

                message_vision(HIM "$N" HIM "将"+baoshi->name()+"和"+
                 weapon->name()+"摆在一起，默运神通使它们变化。\n"+
                   weapon->name()+"发出耀眼的光芒，宝石随之钻入消失了！\n" NOR, me);
                       weapon->set("no_sell",1);
                       destruct(baoshi);
            return 1;

              }

              if(j!=0)
              {
               WEAPON_D->update_baoshi(weapon,i,i%7);

               WSAVE_D->record_weapon(me,weapon,kw[0]);
               me->set("new_weapons/main",kw[0]);

               message_vision(HIM "$N" HIM "将"+baoshi->name()+"和"+
               weapon->name()+"摆在一起，默运神通使它们变化。\n"+
                   weapon->name()+"发出耀眼的光芒，宝石随之钻入消失了！\n" NOR, me);
                      weapon->set("no_sell",1);
                       destruct(baoshi);
               return 1;
               }
             else return notify_fail("你的宝石武器太多了！\n");


}

int help(object me)
{
write(@HELP
指令格式 : shenghua <特殊宝石> at <武器>

这个指令可以让你将某些终极宝石升华武器，让武器具有更大的特殊攻击功能 。


HELP
    );
    return 1;
}
