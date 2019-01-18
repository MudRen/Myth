//      equip.c

#include <dbase.h>
#include <weapon.h>
//  5  inherit "/std/save/wsave.c";

int wear()
{
        object owner;
        mapping armor_prop, applied_prop;
        string *apply, type;

        // Only character object can wear armors.
        if( !(owner = environment())) return 0;
        if( !owner->is_character() ) return 0;

        // If already worn, just recognize it.
        if( query("equipped") ) return 1;

        // Check if we have "armor_prop" defined.
        if( !mapp(armor_prop = query("armor_prop")) ||
             query("weapon_prop/damage")>0 )
                return notify_fail("��ֻ�ܴ����ɵ������ߵĶ�����\n");

        type = query("armor_type");
        if( owner->query_temp("armor/" + type) )
                return notify_fail("���Ѿ�������ͬ���͵Ļ����ˡ�\n");

        owner->set_temp("armor/" + type, this_object());
        apply = keys(armor_prop);
        applied_prop = owner->query_temp("apply");
        if( !mapp(applied_prop) ) applied_prop = ([]);
        for(int i = 0; i<sizeof(apply); i++)
                {
                if( undefinedp(applied_prop[apply[i]]) )
             {
                        applied_prop[apply[i]] = armor_prop[apply[i]];
                            if(metep(owner)) //ת����ĸ���ֵ
                        {
                        applied_prop[apply[i]] += (armor_prop[apply[i]])/4;
                        this_object()->set("mete_armor_prop/"+apply[i],(armor_prop[apply[i]])/4);
                        }
               } else {

                        applied_prop[apply[i]] += armor_prop[apply[i]];
                if(metep(owner)) //ת����ĸ���ֵ
                        {
                        applied_prop[apply[i]] += (armor_prop[apply[i]])/4;
                        this_object()->set("mete_armor_prop/"+apply[i],(armor_prop[apply[i]])/4);
                        }
                                       }
                }       
        owner->set_temp("apply", applied_prop);
        set("equipped", "worn");
        return 1;
}

int wield()
{
        object owner, old_weapon;
        mapping weapon_prop;
        string *apply, type;
        int flag;

        // Only character object can wear armors.
        if( !(owner = environment()) || !owner->is_character() ) return 0;

        // If already wielded, just recognize it.
        if( query("equipped") ) return 1;

        // Check if we have "weapon_prop" defined.
        if( !mapp(weapon_prop = query("weapon_prop")) )
                return notify_fail("��ֻ��װ���ɵ��������Ķ�����\n");

        flag = query("flag");

        if( flag & TWO_HANDED ) {
                if( owner->query_temp("weapon")
                ||      owner->query_temp("secondary_weapon")
                ||      owner->query_temp("armor/shield") )
                        return notify_fail("�����ճ�˫�ֲ���װ��˫��������\n");
                owner->set_temp("weapon", this_object());
        } else {

                // If we are are using any weapon?
                if( !(old_weapon = owner->query_temp("weapon")) )
                    owner->set_temp("weapon", this_object());

                else // If we still have a free hand? 
                if( !owner->query_temp("secondary_weapon")
                &&      !owner->query_temp("armor/shield") ) {

                        // If we can wield this as secondary weapon?
                        if(flag & SECONDARY) {
                                owner->set_temp("secondary_weapon", this_object());
                                if(old_weapon->query("apply/skill_type") &&
                                   old_weapon->query("apply/skill_type") ==
                                   this_object()->query("apply/skill_type") &&
                                   old_weapon->query("skill_type") != 
                                   this_object()->query("skill_type") )  {
                                       owner->set_temp("use_apply_action", 1);
                                           old_weapon->set_temp("use_apply_skill", 1);
                }

                        // If we can switch our old weapon to secondary weapon ?
                        } else if( (int)old_weapon->query("flag") & SECONDARY ) {
                                old_weapon->unequip();
                                owner->set_temp("weapon", this_object());
                                old_weapon->wield();

                        // We need unwield our old weapon before we can use this one.
                        } else
                                return notify_fail("������ȷ�����Ŀǰװ����������\n");

                // We have both hands wearing something.
                } else
                        return notify_fail("�����ճ�һֻ����ʹ��������\n");
        }

        apply = keys(weapon_prop);
        for(int i = 0; i<sizeof(apply); i++)
                {
                owner->add_temp("apply/" + apply[i], weapon_prop[apply[i]]);
               if(metep(owner)) //ת����ĸ��ӹ���
               {owner->add_temp("apply/" + apply[i], (weapon_prop[apply[i]])/4);
               this_object()->set("mete_apply/"+apply[i],(weapon_prop[apply[i]])/4);}
               }
        if(owner->query_temp("use_apply_action") == 1) {
           owner->reset_apply_action();
        }
    else        
           owner->reset_action();
        set("equipped", "wielded");
        return 1;
}

int unequip()
{
        object owner, weapon;
        mapping prop, applied_prop,mete_prop;
        string *apply, equipped;

        if( !environment() ) return 0;
        if( !(owner = environment())->is_character() ) return 0;

        if( !stringp(equipped = query("equipped")) )
                return notify_fail("��Ŀǰ��û��װ������������\n");

//      if( equipped=="second_wield") {
//              delete("equipped");
//              return 1;
//      }


        if( equipped=="wielded" ) {
                if( (weapon=(object)owner->query_temp("weapon")) == this_object() )
                        owner->delete_temp("weapon");
                else if( (object)owner->query_temp("secondary_weapon") == this_object() )
                        owner->delete_temp("secondary_weapon");
                owner->delete_temp("use_apply_action");
                // added by snowcat 6/21 (ling jian)
                if (weapon)
                        weapon->delete_temp("use_apply_skill");
                prop = query("weapon_prop");
                if (query("mete_apply"))
                         mete_prop=query("mete_apply");
                owner->delete_temp("perf_quick");
                owner->reset_action();
        } else if( equipped=="worn" ) {
                owner->delete_temp("armor/" + query("armor_type") );
                prop = query("armor_prop");
                if (query("mete_armor_prop"))
                         mete_prop=query("mete_armor_prop");
        }

        apply = keys(prop);
        applied_prop = owner->query_temp("apply");
        for(int i = 0; i<sizeof(apply); i++)
                {// To support array apply, we cannot add_temp() here.
                applied_prop[apply[i]] -= prop[apply[i]];
        if(metep(owner) && mete_prop)
        //ת����������������          
                applied_prop[apply[i]] -= mete_prop[apply[i]];}
        delete("equipped");
        weapon=(object)owner->query_temp("secondary_weapon");
        // add by bbs, April 28.
        if(weapon) {
                weapon->unequip();
                weapon->wield();
        }
        return 1;
}

