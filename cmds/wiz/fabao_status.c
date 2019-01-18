//  fabao_status.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   object ob;
   string ob_id;
   object *inv;
   mapping fabao;
   int  i;
   string series_no;
   
    seteuid(getuid());
    
    if(!arg)
       ob = me; 
    else  {
       ob = find_player(arg);
       if( !ob )  ob = find_living(arg);
       if( !ob )  return notify_fail("��Ҫ�쿴˭�ķ���״̬��\n");
    }
    
    if( ob!=me && !wizardp(me) )
       return notify_fail("ֻ����ʦ�ܲ쿴���˵ķ���״̬��\n"); 

    fabao = ob->query("fabao");
    if( !mapp(fabao) )
       return notify_fail(ob->query("name")+"Ŀǰû���κη�����\n");           
 
    inv = all_inventory(ob);
    ob_id = getuid(ob);
    for(i=0; i<sizeof(inv); i++)  { 
       if( (series_no=inv[i]->query("series_no")) &&
        inv[i]->query("owner_id") == ob_id ) {
		   if( series_no == "1" )  {
              write(sprintf("%s�˺���Ϊ %d��\n", inv[i]->query("name"),
                 inv[i]->query("weapon_prop/damage") ));
           }
		   else if( series_no == "2" || series_no == "3" )  {
              write(sprintf("%s������Ϊ %d��\n", inv[i]->query("name"),
                  inv[i]->query("armor_prop/dodge") ));
              write(sprintf("%s�ֿ���Ϊ %d��\n", inv[i]->query("name"),
                  inv[i]->query("armor_prop/armor") ));
              write(sprintf("%s�ڹ��ֿ���Ϊ %d��\n", inv[i]->query("name"),
                  inv[i]->query("armor_prop/armor_vs_force") ));
              write(sprintf("%sħ��������Ϊ %d��\n", inv[i]->query("name"),
                  inv[i]->query("armor_prop/spells") ));
              write(sprintf("%sħ���ֿ���Ϊ %d��\n", inv[i]->query("name"),
                  inv[i]->query("armor_prop/armor_vs_spells") ));
          } 
       }
    }
    
    return 1;          
}

int help(object me)
{
        write(@HELP
ָ���ʽ : fabao_status [<ĳ��>]

���ָ����������ѯ����״̬��

��ʦ���Բ�ѯ�κ��˵ķ���״����

HELP
    );
    return 1;
}

