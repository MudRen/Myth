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
                return notify_fail("��Ҫ�ϲ�ʲô��Ʒ��\n");

        if (sscanf(arg,"%s at %s",bshi,wes)!=2)
                return notify_fail("��Ҫ����ʲô��ʯ��ʲô������<ָ��>:shenghua xxx at xxx \n");


        if (me->is_busy())
                return notify_fail("��æ����������������������ɣ�\n");

        if (me->is_fighting())
                return notify_fail("���������ڴ�ܣ�ûʱ������Щ���顣\n");
        if (!( baoshi=present (bshi,me)))
                return notify_fail("������û�������Ʒ��\n");
        if (!( weapon=present (wes,me)))
                return notify_fail("������û�����������\n");
        if (!(i=(int)baoshi->query("b_lvl")) || i < 21)
                return notify_fail("�����������ʯ������������\n");
        if( !weapon->query("weapon_prop") )
                return notify_fail("��ֻ�������ɵ��������Ķ�����\n");
        if( ( weapon->query_unique() && !weapon->query("fabao"))
            || weapon->query("weapon")
            || weapon->query("unique")
            || weapon->query("weapon")

            )
                  return notify_fail("����������ܽ��б�ʯ������\n");
        if (weapon->query("owner_id") && weapon->query("owner_id")!=me->query("id"))
                  return notify_fail("�������������ģ����ܽ��б�ʯ������\n");
         if (weapon->query("equipped"))    return notify_fail("������ȷ������������\n");
        if (me->query("max_sen") < 1500)
                return notify_fail("�����ڵľ�����Ϊ���ޣ���"
                                   "��ʩչ��˼���ķ�����\n");

        if (me->query("sen") < 1000)
                return notify_fail("�����ھ��񲻼ã��޷�ʩչ������\n");
        if(  weapon->query_unique() && weapon->query("fabao"))
           {
           WEAPON_D->update_baoshi(weapon,i,i%7);
        weapon->save();
                   message_vision(HIM "$N" HIM "��"+baoshi->name()+"��"+
                   weapon->name()+"����һ��Ĭ����ͨʹ���Ǳ仯��\n"+
                   weapon->name()+"����ҫ�۵Ĺ�â����ʯ��֮������ʧ�ˣ�\n" NOR, me);
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
              message_vision(HIM "$N" HIM "��"+baoshi->name()+"��"+
               weapon->name()+"����һ��Ĭ����ͨʹ���Ǳ仯��\n"+
                   weapon->name()+"����ҫ�۵Ĺ�â����ʯ��֮������ʧ�ˣ�\n" NOR, me);
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

                message_vision(HIM "$N" HIM "��"+baoshi->name()+"��"+
                 weapon->name()+"����һ��Ĭ����ͨʹ���Ǳ仯��\n"+
                   weapon->name()+"����ҫ�۵Ĺ�â����ʯ��֮������ʧ�ˣ�\n" NOR, me);
                       weapon->set("no_sell",1);
                       destruct(baoshi);
            return 1;

              }

              if(j!=0)
              {
               WEAPON_D->update_baoshi(weapon,i,i%7);

               WSAVE_D->record_weapon(me,weapon,kw[0]);
               me->set("new_weapons/main",kw[0]);

               message_vision(HIM "$N" HIM "��"+baoshi->name()+"��"+
               weapon->name()+"����һ��Ĭ����ͨʹ���Ǳ仯��\n"+
                   weapon->name()+"����ҫ�۵Ĺ�â����ʯ��֮������ʧ�ˣ�\n" NOR, me);
                      weapon->set("no_sell",1);
                       destruct(baoshi);
               return 1;
               }
             else return notify_fail("��ı�ʯ����̫���ˣ�\n");


}

int help(object me)
{
write(@HELP
ָ���ʽ : shenghua <���ⱦʯ> at <����>

���ָ��������㽫ĳЩ�ռ���ʯ�������������������и�������⹥������ ��


HELP
    );
    return 1;
}
