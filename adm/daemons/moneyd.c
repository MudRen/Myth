// moneyd.c  Ǯ�Ĺ���

// by Xiang@XKX (95/12/22)
// Update by Doing for Hell

#pragma optimize
#pragma save_binary

string money_str(int amount)
{
        // returns a chinese string of `amount` of money
        string output;

        if (amount / 10000) {
                output = chinese_number(amount / 10000) + "���ƽ�";
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
                output = output + chinese_number(amount / 100) + "������";
                amount %= 100;
        }
        if (amount)
                return output + chinese_number(amount) + "��ͭǮ";
        return output;
}

string price_str(int amount)
{
        // returns a chinese string of `amount` of money
        string output;

        if (amount < 1)
                amount = 1;

        if (amount / 10000) {
                output = chinese_number(amount / 10000) + "���ƽ�";
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
                if (output != "")
                        output += "��" + chinese_number(amount / 100) + "������";
                else
                        output = chinese_number(amount / 100) + "������";
                amount %= 100;
        }
        if (amount)
                if (output != "")
                        return output + "��" + chinese_number(amount) + "��ͭ��";
                else
                        return chinese_number(amount) + "��ͭ��";
        return output;
}

void pay_player(object who, int amount)
{
        int v;
        object ob;

        seteuid(getuid());
        if (amount < 1)
                amount = 1;
        if (v = amount / 10000)
        {
                ob = new(GOLD_OB);
                ob->set_amount(amount / 10000);
                ob->move(who, 1);
                amount %= 10000;
        }
        if (amount / 100)
        {
                ob = new(SILVER_OB);
                ob->set_amount(amount / 100);
                ob->move(who, 1);
                amount %= 100;
        }
        if (amount)
        {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who, 1);
        }
}

int player_pay(object who, int amount)
{
        object t_ob, g_ob, s_ob, c_ob;
        int tc, gc, sc, cc, left;
        int v;

        seteuid(getuid());

        if ((amount >= 100000 || who->query("doing") == "scheme") &&
            objectp(t_ob = present("cash_money", who)))
                // ������Ʒ���Ǽƻ��п���ʹ����Ʊ
                tc = t_ob->query_amount();
        else
        {
                tc = 0;
                t_ob = 0;
        }
        if (g_ob = present("gold_money", who))
                gc = g_ob->query_amount();
        else
                gc = 0;
        if (s_ob = present("silver_money", who))
                sc = s_ob->query_amount();
        else
                sc = 0;
        if (c_ob = present("coin_money", who))
                cc = c_ob->query_amount();
        else
                cc = 0;
        
        v = cc + sc * 100 + gc * 10000;
        if (amount < 100000 && v < amount)
        {
                if (present("cash_money", who))
                        return 2;
                else
                        return 0;
        }

        v += tc * 100000;
        if (v < amount) 
                return 0;
        else {
                left = v - amount;
                if (tc)
                {
                        tc = left / 100000;
                        left %= 100000;
                }
                gc = left / 10000;
                left = left % 10000;
                sc = left / 100;
                cc = left % 100;

                if (t_ob && ! g_ob && gc)
                {
                        g_ob = new(GOLD_OB);
                        g_ob->move(who, 1);
                }

                if (t_ob)
                        t_ob->set_amount(tc);
                if (g_ob)
                        g_ob->set_amount(gc);
                else sc += (gc * 100);
                if (s_ob)
                        s_ob->set_amount(sc);
                else if (sc) {
                        s_ob = new(SILVER_OB);
                        s_ob->set_amount(sc);
                        s_ob->move(who, 1);
                }
                if (c_ob)
                        c_ob->set_amount(cc);
                else if (cc) {
                        c_ob = new(COIN_OB);
                        c_ob->set_amount(cc);
                        c_ob->move(who, 1);
                }

                return 1;
        }
}

int player_carry(object ob)
{
        object cash_ob;
        object gold_ob;
        object silver_ob;
        object coin_ob;
        int gold;

        gold = ob->query("balance") / 10000;

        cash_ob = present("cash_money", ob);
        gold_ob = present("gold_money", ob);
        silver_ob = present("silver_money", ob);
        coin_ob = present("coin_money", ob);
        if (cash_ob) gold += cash_ob->query_amount() * 10;
        if (gold_ob) gold += gold_ob->query_amount();
        if (silver_ob) gold += silver_ob->query_amount() / 100;
        if (coin_ob)   gold += coin_ob->query_amount() / 10000;
        return gold;
}

// all_inventory player have value
// mudring Sep/11/2002
int player_have(object ob)
{
        int value;
        object cash, gold, silver, coin;

        cash = present("cash_money", ob);
        gold = present("gold_money", ob);
        silver = present("silver_money", ob);
        coin = present("coin_money", ob);

        value = 0;
        if (cash) value += cash->value();
        if (gold) value += gold->value();
        if (silver) value += silver->value();
        if (coin) value += coin->value();

        return value;
}

