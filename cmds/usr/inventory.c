//inventory.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object *inv, ob;
        string s1, s2;
        int i, j, total, t1, t2, t3, t4, temp;

        if( wizardp(me) && arg ) {
                ob = find_player(arg);
                if( !ob ) ob = find_living(arg);
                if( !ob ) ob = present(arg, environment(me));
        }

        if( !ob ) ob = me;

        inv = all_inventory(ob);

        if( !(total = sizeof(inv) ) ) {
                write((ob == me)? "Ŀǰ������û���κζ�����\n"
                        : ob->name() + "����û��Я���κζ�����\n");
                return 1;
        }

/*
        printf("%s���ϴ���������Щ����(���� %d%%)��\n%s\n",
                (ob == me)? "��": ob->name(),
                (int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance(),
                implode(map_array(inv, "inventory_desc", this_object()), "\n") );
*/
        t1 = 0;
        t2 = 0;
        t3 = 0;
        t4 = 0;
        for( i = 0; i < total; i ++ ) {
                if( mapp( inv[i]->query("armor_prop")) && !mapp(inv[i]->query("weapon_prop")) ) t3 ++;
                else if( mapp( inv[i]->query("weapon_prop")) ) t1 ++;
                else if( mapp( inv[i]->query("horse_prop")) ) t2 ++;
                else t4 ++;
        }
        
        i = (int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance();
        printf(HIR"\n%sӵ������%s������"NOR""HIW"������ %d%%����\n"NOR,
                (ob == me)? "��": ob->name(), CHINESE_D->chinese_number( total ), ( i < 0 ) ?  0 : i );
        printf("������������������������������������������������������������������������������\n");
        printf(HIC "\n%10s%-40s%-20s\n\n" NOR, " ", "��    ��", "��    ��");
        
        for( i = 0; i < ( ( t1 > t2 ) ? t1 : t2 ); i++ ) {
                s1 = " ";
                s2 = " ";
                if( t1 >= i + 1 ) {
                        for( j = 0, temp = 0; j < total; j ++ ) {
                                if( mapp( inv[j]->query("weapon_prop")) ) {
                                        temp ++;
                                        if( temp >= i + 1 ) break;
                                }
                        }
                        s1 = ( ( inv[j]->query("equipped") ) ? HIC "��" NOR: "  " )
                                + ( (inv[j]->query_amount()) ? CHINESE_D->chinese_number(inv[j]->query_amount()) + inv[j]->query("base_unit") : "" )
                                + inv[j]->name() + " (" + inv[j]->query("id") + ")";
                }
                if( t2 >= i + 1 ) {
                        for( j = 0, temp = 0; j < total; j ++ ) {
                                if( mapp( inv[j]->query("horse_prop")) ) {
                                        temp ++;
                                        if( temp >= i + 1 ) break;
                                }
                        }
                        s2 = ( ( inv[j]->query("equipped") ) ? HIC "��" NOR: "  " )
                                + ( (inv[j]->query_amount()) ? CHINESE_D->chinese_number(inv[j]->query_amount()) + inv[j]->query("base_unit") : "" )
                                + inv[j]->name() + " (" + inv[j]->query("id") + ")";
                }
                for(j = 0, temp = 0; j < strlen(s1) ; j++, temp++) 
                        if( (int)s1[j] == 27 ) 
                                for(temp--; j < strlen(s1) && s1[j] != 'm'; j++ );
                for(j = temp; j < 40; j++ ) s1 += " ";
                write(s1 + s2 + "\n");
        }

        printf(HIC "\n%10s%-40s%-20s\n\n" NOR, " ", "��    ��", "������Ʒ");
        
        for( i = 0; i < ( ( t3 > t4 ) ? t3 : t4 ); i++ ) {
                s1 = " ";
                s2 = " ";
                if( t3 >= i + 1 ) {
                        for( j = 0, temp = 0; j < total; j ++ ) {
                                if( mapp( inv[j]->query("armor_prop")) 
                                &&      !mapp(inv[j]->query("weapon_prop")) ) {
                                        temp ++;
                                        if( temp >= i + 1 ) break;
                                }
                        }
                        s1 = ( ( inv[j]->query("equipped") ) ? HIC "��" NOR: "  " )
                                + ( (inv[j]->query_amount()) ? CHINESE_D->chinese_number(inv[j]->query_amount()) + inv[j]->query("base_unit") : "" )
                                + inv[j]->name() + " (" + inv[j]->query("id") + ")";
                }
                if( t4 >= i + 1 ) {
                        for( j = 0, temp = 0; j < total; j ++ ) {
                                if( !mapp( inv[j]->query("armor_prop")) 
                                &&      !mapp( inv[j]->query("weapon_prop"))
                                &&      !mapp( inv[j]->query("horse_prop")) ) {
                                        temp ++;
                                        if( temp >= i + 1 ) break;
                                }
                        }
                        s2 = ( ( inv[j]->query("equipped") ) ? HIC "��" NOR: "  " )
                                + ( (inv[j]->query_amount()) ? CHINESE_D->chinese_number(inv[j]->query_amount()) + inv[j]->query("base_unit") : "" )
                                + inv[j]->name() + " (" + inv[j]->query("id") + ")";
                }
                for(j = 0, temp = 0; j < strlen(s1) ; j++, temp++) 
                        if( (int)s1[j] == 27 ) 
                                for(temp--; j < strlen(s1) && s1[j] != 'm'; j++ );
                for(j = temp; j < 40; j++ ) s1 += " ";
                write(s1 + s2 + "\n");
        }
        printf("������������������������������������������������������������������������������\n");

        return 1;
}

string inventory_desc(object ob)
{
        return sprintf("%s%s",
                ob->query("equipped")? HIC "��" NOR:"  ",
                ob->short()
        );
}

int help (object me)
{
        write(@HELP
ָ���ʽ��inventory
          inventory [����]      ����ʦר�ã�
 
�г�Ŀǰ������Я����������Ʒ����ָ����ԡ�i�����档
 
���ѶϢ��get, drop
HELP
        );
        
        return 1;
}

